inherit ROOM;
void create()
{
  set("short","�׺Ӱ���");
  set("long",@LONG
һ��С������������������ȥ���������Ǹ߸ߵ�«έ�ԣ����������ǣ���
���غӶ��¾��������ǡ�·���м������ᣬһ���ײ�����������ŤŤ��д��һ��
���ơ��֡����ϲ�ʱ������ȸ�ġ�ߴߴ�������Ľ����������м�ֻ�洬���ڴ��㣬
������������ƺ��Ǻÿ���
LONG);
  set("exits",([
    "northeast"   : "/d/nanyang/nanmen",
    "south"  : __DIR__"fancheng",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

