inherit ROOM;
void create()
{
  set("short","��ɽ");
  set("long",@LONG
��ɽ֮�գ��Թ����������¹�ʱ���������ӵ����ʾ�����֣����
�ڴ��⵽�����ķ�����ȫ����û��������Ȼ��ɽ�п����˹ٵ�����ż
����ǿ����٣�����ҹ����ǵ�Ұ��Ҳ�Ĵ����
LONG);
  set("exits",([
    "east"   : __DIR__"xiaoshan3",
    "west"   : __DIR__"xiaoshan1",
  ]));
     set("objects",([
           __DIR__"npc/wolf" : 1,
      ]));
       set("outdoors","zhongyuan");
  setup();
}

