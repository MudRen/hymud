inherit ROOM;


void create()
{
   set("short","������");
   set("long",@LONG
���������س�����̫����������޽��ġ�һǧ����������һֱ������⸽��
����Ķ�����ȥ��ʮ����ǳɶ��ǣ��������ẽ�����һ����ɽ��
LONG);
   set("exits",([
      "southeast"   : __DIR__"pingyuan7",
      "west"  : __DIR__"qingcheng_shan",
      "east"  : "/d/chengdu/nanheqiaow",
   ]));
   setup();
        set("outdoors","xinan");
}
