inherit ROOM;
void create()
{
  set("short","��·");
  set("long",@LONG
��һ��������ԭ���أ�����ƽ̹,�������.������Ϊ����ĻƺӾ������ģ�
�����ص��ϰ��մ������޾������ѡ�
LONG);
  set("exits",([
    "north"   : __DIR__"tulu2",
    "south"  : __DIR__"tulu4",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

