inherit ROOM;
void create()
{
  set("short","崤山");
  set("long",@LONG
崤山之险，自古闻名。秦穆公时，大将孟明视等人率军进攻郑国，在此遭到
晋国的伏击，全军覆没。现在虽然在山中开辟了官道，仍偶尔有强盗打劫，到了
夜里，豺狼等野兽也四处活动。
LONG);
  set("exits",([
    "northeast"   : __DIR__"mianchi",
    "west"   : __DIR__"xiaoshan2",
  ]));
    set("objects",([
        __DIR__"npc/wolf":1,
    ]));
   set("outdoors","zhongyuan");
  setup();
}

