doctl compute droplet create perf-ninja \
  --image ubuntu-23-10-x64 \
  --size c-2 \
  --region fra1 \
  --user-data-file ./user-data.sh \
  --enable-private-networking \
  --ssh-keys "4e:e3:92:1c:c9:56:51:99:bc:9f:27:aa:8a:e8:ad:98" \
  --verbose \
  --wait 
