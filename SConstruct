#
# Fabric Engine 2.1.0-alpha
# EDKObjects EDK Sample
#
# Copyright 2010-2015 Fabric Software Inc. All rights reserved.
#

import os, sys, glob

try:
  fabricPath = os.environ['FABRIC_DIR']
except:
  print "You must set FABRIC_DIR in your environment."
  print "Refer to README.txt for more information."
  sys.exit(1)

SConscript('SConscript')
Import('fabricBuildEnv')

fabricBuildEnv.Append(CPPPATH = [
  './cpp'
  ])

os.makedirs('./GenCPP/')

old_files = glob.glob('./GenCPP/*.*')
for file in old_files:
    os.remove(file)

cppFiles = glob.glob('./CustomCPP/*.cpp')
klFiles = glob.glob('./Exts/AsyncTask/*.kl')
dll = fabricBuildEnv.Extension(
  'AsyncTask',
  klFiles,
  cppFiles,
  './Exts/AsyncTask/AsyncTask.fpm.json'
  )

fabricBuildEnv.Install('./Exts/AsyncTask', dll)

cppFiles = cppFiles + glob.glob('./GenCPP/*.cpp')

for i in range(len(cppFiles)):
  cppFiles[i] = cppFiles[i].replace('\\', '/')
  cppFiles[i] = '../GenCPP/' + os.path.relpath(cppFiles[i], './GenCPP')

# Build a VS project to go along with this dll
# We can use this for debugging the project later.
fabricBuildEnv.MSVSProject(target = './MSVS/AsyncTask' + fabricBuildEnv['MSVSPROJECTSUFFIX'],
                srcs = cppFiles,
                buildtarget = dll[0],
                variant = 'Debug|x64')

