inherit ROOM;
void create()
{
  set("short","��·");
  set("long",@LONG
��һ��������ԭ���أ�����ƽ̹,�������.������Ϊ����ĻƺӾ������ģ�
�����ص��ϰ��մ������޾������ѡ������Ƿ�ţɽ������ɽ�����Ͼ��������ˡ�
LONG);
  set("exits",([
    "north"   : __DIR__"tulu3",
    "southwest"  : __DIR__"funiu_shan",
  ]));
    set("outdoors","zhongyuan");
  setup();
}

