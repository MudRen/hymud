inherit ROOM;
void create()
{
  set("short","终南山下");
  set("long",@LONG
终南山是上古神仙居住的地方。传说鲁班青年时就是在终南山上遇仙学艺，
后来终于成了一代奇才，被尊为木匠的祖师爷。
    唐朝末年，宦官专权，一批大臣暗中商量要除掉他们，不料事情败露，宫廷
中派出许多刺客追杀。其中一个叫李训的翰林学士一直跑到终南山上，不料还是
被刺死。后人为了纪念他，在山上为他造了衣冠冢。
LONG);
  set("exits",([
    "westup"   : __DIR__"shouyang_shan",
    "northeast"   : __DIR__"xiangtian",
  ]));
   set("outdoors","zhongyuan");
    setup();

}

