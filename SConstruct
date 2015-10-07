#
# Fabric Engine 2.1.0-alpha
# EDKObjects EDK Sample
#
# Copyright 2010-2015 Fabric Software Inc. All rights reserved.
#

import os, sys, glob, shutil, platform

try:
  fabricPath = os.environ['FABRIC_DIR']
except:
  print "You must set FABRIC_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)

SConscript('SConscript')
Import('fabricBuildEnv')

fabricBuildEnv.Append(CPPPATH = [
  'cpp'
  ])
fabricBuildEnv.Append( RPATH = fabricBuildEnv.Literal('\\$$ORIGIN'))

# Clean generated folder
genFolder = 'GenCPP'
if os.path.exists(genFolder):
  shutil.rmtree(genFolder)
os.makedirs(genFolder)


cppFiles = glob.glob('CustomCPP/*.cpp')
klFiles = glob.glob('exts/AsyncTask/*.kl')
dll = fabricBuildEnv.Extension(
  'AsyncTask',
  klFiles,
  cppFiles,
  'exts/AsyncTask/AsyncTask.fpm.json'
  )

fabricBuildEnv.Install('exts/AsyncTask', dll)

cppFiles = cppFiles + glob.glob('GenCPP/*.cpp')

for i in range(len(cppFiles)):
  cppFiles[i] = cppFiles[i].replace('\\', '/')
  cppFiles[i] = '../GenCPP/' + os.path.relpath(cppFiles[i], 'GenCPP')

if platform.system() == 'Windows':
  # Build a VS project to go along with this dll
  # We can use this for debugging the project later.
  fabricBuildEnv.MSVSProject(target = 'MSVS/AsyncTask' + fabricBuildEnv['MSVSPROJECTSUFFIX'],
                srcs = cppFiles,
                buildtarget = dll[0],
                variant = 'Debug|x64')

