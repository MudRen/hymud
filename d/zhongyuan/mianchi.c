inherit ROOM;
void create()
{
  set("short","�ų�");
  set("long",@LONG
����ĩ�꣬��������ͬ�Ի����ڴ�������������������Ӻ������������
�������ȴ��������������ӣ�������ƽ�������������������ɽ�����������ˮ
�����������ˡ�
LONG);
  set("exits",([
    "east"   : __DIR__"jianshui",
    "southwest"   : __DIR__"xiaoshan3",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

