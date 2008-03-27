###
### First, collect the TOP_DIR

SCAN_DIR=/home/samba/samba/newspiritsync/public_html
TOP_DIR=`pwd`

rm -fv rung.sh

echo "cd ${SCAN_DIR}" >> rung.sh

python BotScanGrep.py -e *.zip >> rung.sh
python BotScanGrep.py -e *.gz >> rung.sh

chmod 755 rung.sh
./rung.sh > botscan_grep.db

echo "** Done **"

