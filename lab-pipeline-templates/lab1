node {
   def gccHome = "/usr/bin/gcc"
   stage('Preparation') { 
   //pull down Mario C code from repo
      git 'https://github.com/linuxacademy/content-pipelines-cje-labs.git'
   }
   stage('Build') {
      //if system is Unix compile C source code
      if (isUnix()) {
         sh "'${gccHome}' --std=c99 -o mario lab1_lab2/mario.c"
      } else {
         echo "Not a Unix system, build not possible"
      }
   }
   stage('Results') {
      archive 'mario'
   }
}
