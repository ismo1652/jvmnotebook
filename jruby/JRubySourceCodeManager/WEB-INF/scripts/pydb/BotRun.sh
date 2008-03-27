###

rm -fv run.sh
rm -Rf ./dump
mkdir -pv ./dump


HOME_DIR=/home/samba/samba/newspiritsync/public_html/
python BotScanDir.py -e *.zip -i ${HOME_DIR} >> run.sh
python BotScanDir.py -e *.gz -i ${HOME_DIR} >> run.sh

chmod 755 run.sh
./run.sh

echo "** Done **"

