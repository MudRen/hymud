inherit ROOM;
void create()
{
  set("short","С·");
  set("long",@LONG
������һ���ּ�С·�ϣ������Ǻ��Ŀ�֦��Ҷ�����߶���ï�ܵ����֣���
�ָ�����С����֦ͷ�質��һֱ�������䵱ɽ��������������ˡ�
LONG);
  set("exits",([
    "northwest"   : __DIR__"wudang_shan",
    "east"  : __DIR__"xiangyang",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

