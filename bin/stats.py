#!/usr/bin/python

import sys
import datetime
import subprocess
import git
from git	import Repo
import pathlib
import os
import locale


locale.setlocale(locale.LC_ALL, '')  # Use '' for auto

# Get	the current	Git Repository	(as a	global)
repo = git.Repo(".")

# Initialize the sets of file	types	we	will process
h_files = set()
c_files = set()
cpp_files =	set()
py_files	= set()
web_files =	set()
asm_files =	set()
markdown_files	= set()
image_files	= set()
other_files	= set()


def print_title():
	print( "Project Statistics" )
	print( "==================" )
	print( "" )


def print_shields_io_tags():
	GITHUB_USERNAME="marknelsonengineer"
	GITHUB_REPO="DTMF_Decoder"
	STYLE="social"

	repo1=f"![GitHub code size	in	bytes](https://img.shields.io/github/languages/code-size/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	repo2=f"![GitHub repo size](https://img.shields.io/github/repo-size/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	repo3=f"![GitHub contributors](https://img.shields.io/github/contributors/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"

	commit1=f"![GitHub commit activity](https://img.shields.io/github/commit-activity/w/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	commit2=f"![GitHub last	commit](https://img.shields.io/github/last-commit/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	issue1=f"![GitHub	issues](https://img.shields.io/github/issues-raw/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	issue2=f"![GitHub	closed issues](https://img.shields.io/github/issues-closed-raw/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	social1=f"![GitHub forks](https://img.shields.io/github/forks/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"
	social2=f"![GitHub Repo	stars](https://img.shields.io/github/stars/{GITHUB_USERNAME}/{GITHUB_REPO}?style={STYLE})"

	print()
	print( "## GitHub	Statistics"	)
#
#	print_number_of_commits
#
	print(  "| Repository								  | Commits							| Issues						  | Social							|"	)
	print(  "|-------------------------------------|---------------------------|-------------------------|---------------------------|"	)
	print( f"| {repo1} <br/> {repo2}	<br/>	{repo3} | {commit1} <br/> {commit2}	| {issue1} <br/> {issue2} | {social1} <br/> {social2}	|"	)


def print_tags():
# Use	the following to get	the tag/release history
# $ git tag	--sort=v:refname --format="%(tag)|%(contents)|%(creator)"
	print( "" )
	print( "## Tags" )

	tags = repo.tags

	if	len(tags) == 0:
		print( "No tags" )
	else:
		print( "| Tag | Date	| Author	|"	)
		print( "|-----|------|--------|"	)

#		git for-each-ref --sort=creatordate	--format	'|%(refname:strip=2)|%(creatordate)|%(authorname)|' refs/tags
		result =	subprocess.run(['git', 'for-each-ref',	'--sort=creatordate', '--format', '|%(refname:strip=2)|%(creatordate)|%(authorname)|',	'refs/tags'], stdout=subprocess.PIPE)
		print( result.stdout.decode('utf-8') )

	print( "" )



def print_date():
	print( "" )
	now =	datetime.datetime.now()
	print( "Automatically generated on " +	now.strftime("%c") )


def process_gcc_files( rowName, fileList	):
	print(len( fileList ))
	if( len( fileList ) == 0 ):
		return

	numFiles = len( fileList )

	totalBytes = 0
	totalLines = 0
	for f in fileList:
		totalBytes += os.path.getsize( f )
		totalLines += sum(1 for line in open( f, "rb" ))
		result = subprocess.run(['gcc', '-fpreprocessed', '-dD', '-w', '-E', f], stdout=subprocess.PIPE)

	print( f"|{rowName}|{numFiles:n}|{totalLines:n}|{totalBytes:n}|n/a|n/a|" )


def process_text_files( rowName, fileList	):
	if( len( fileList ) == 0 ):
		return

	numFiles = len( fileList )

	totalBytes = 0
	totalLines = 0
	for f in fileList:
		totalBytes += os.path.getsize( f )
		totalLines += sum(1 for line in open( f, "rb" ))

	print( f"|{rowName}|{numFiles:n}|{totalLines:n}|{totalBytes:n}|n/a|n/a|" )


def process_data_files(	rowName,	fileList	):
	if( len( fileList ) == 0 ):
		return

	numFiles = len( fileList )

	totalBytes = 0
	for f in fileList:
		totalBytes += os.path.getsize( f )

	print( f"|{rowName}|{numFiles:n}|n/a|{totalBytes:n}|n/a|n/a|" )


def process_files():
	print( "| Type | Files | Lines | Bytes | Working Lines | Working Bytes |" )
	print( "|------|------:|------:|------:|--------------:|--------------:|" )

	for entry in repo.heads.master.commit.tree.traverse():
		if	not os.path.isfile( entry.name ):
			continue

		file_extension	= pathlib.Path( entry.name	).suffix
		print( entry.path + "***" + entry.name + "---" +	file_extension	)
		if( file_extension == '.h'	):
			h_files.add( entry.path	)
		elif(	file_extension	==	'.c' ):
			c_files.add( entry.path	)
		elif(	file_extension	==	'.cpp' ):
			cpp_files.add(	entry.path )
		elif(	file_extension	==	'.py'	):
			py_files.add( entry.path )
		elif(	file_extension	in	['.html', '.css']	):
			web_files.add(	entry.path )
		elif(	file_extension	==	'.asm' ):
			asm_files.add(	entry.path )
		elif(	file_extension	==	'.md'	):
			markdown_files.add( entry.path )
		elif(	file_extension	in	['.svg',	'.png', '.ico', '.png',	'.jpg', '.jpeg', '.dot'] ):
			image_files.add( entry.path )
		else:
			other_files.add( entry.path )

	process_gcc_files( ".h", h_files )
	process_gcc_files( ".c", c_files )
	process_gcc_files( ".cpp", cpp_files )
	process_text_files( "HTML", web_files )
	process_text_files( "Markdown", markdown_files )
	process_data_files( "Images", image_files )
	process_data_files( "Other	Files", other_files )



# The	Main Program

with open('STATISTICS.md',	'w') as redirected_output:
	sys.stdout = redirected_output #	Redirect	stdout
	print_title()

	process_files()

#	print_tags()

#	print_shields_io_tags()

#	print_date()
