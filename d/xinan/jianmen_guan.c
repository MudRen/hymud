inherit ROOM;


void create()
{
   set("short","���Ź�");
   set("long",@LONG
���Źش��ڴ�С��ɽ֮�䣬�С�һ�򵱹أ����Ī����֮�ơ�������ǽ����ˡ�
    ���Ե���������ѣ����������족�������ɽ����խ��᫣�����һ�أ��岽
һ�գ���һ�����񣬾ͻ�ʧ�����ɽ����ˤ�÷�����ǡ�
LONG);
   set("exits",([
      "north"   : __DIR__"qipan_guan",
      "south"  : __DIR__"jianmen_shan",
   ]));
   setup();
        set("outdoors","xinan");
}
