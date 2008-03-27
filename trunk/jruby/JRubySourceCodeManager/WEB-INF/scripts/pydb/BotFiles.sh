###
### First, collect the TOP_DIR

DB_FILE=scan_files.db
rm -fv $DB_FILE 

python BotScanFiles.py -e *.zip >> $DB_FILE 
python BotScanFiles.py -e *.gz >> $DB_FILE 

python BotScanFiles.py -e *.scm >> $DB_FILE 
python BotScanFiles.py -e *.rb >> $DB_FILE 
python BotScanFiles.py -e *.lisp >> $DB_FILE 
python BotScanFiles.py -e *.bat >> $DB_FILE 
python BotScanFiles.py -e *.txt >> $DB_FILE 
python BotScanFiles.py -e *.jsp >> $DB_FILE 
python BotScanFiles.py -e *.java >> $DB_FILE 
python BotScanFiles.py -e *.py >> $DB_FILE 
python BotScanFiles.py -e *.xml >> $DB_FILE 
python BotScanFiles.py -e *.sql >> $DB_FILE 
python BotScanFiles.py -e *.js >> $DB_FILE 
python BotScanFiles.py -e *.cs >> $DB_FILE 
python BotScanFiles.py -e *.html >> $DB_FILE 
python BotScanFiles.py -e *.htm >> $DB_FILE 
python BotScanFiles.py -e *.sh >> $DB_FILE 
python BotScanFiles.py -e *.rhtml >> $DB_FILE 
python BotScanFiles.py -e *.tld >> $DB_FILE 
python BotScanFiles.py -e *.abcl >> $DB_FILE 
python BotScanFiles.py -e *.cpp >> $DB_FILE 
python BotScanFiles.py -e *.c >> $DB_FILE 

echo "** Done **"

