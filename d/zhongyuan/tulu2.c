inherit ROOM;
void create()
{
  set("short","��·");
  set("long",@LONG
��һ��������ԭ���أ�����ƽ̹,�������.������Ϊ����ĻƺӾ������ģ�
�����ص��ϰ��մ������޾������ѡ�
   ������������������ɽ��
LONG);
  set("exits",([
    "north"   : __DIR__"tulu1",
    "south"  : __DIR__"tulu3",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

