inherit ROOM;
void create()
{
  set("short","��ɽ");
  set("long",@LONG
��ɽ֮�գ��Թ����������¹�ʱ���������ӵ����ʾ�����֣�����ڴ��⵽
�����ķ�����ȫ����û��������Ȼ��ɽ�п����˹ٵ�����ż����ǿ����٣�����
ҹ����ǵ�Ұ��Ҳ�Ĵ����
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

