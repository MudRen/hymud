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
    "northwest"   : __DIR__"longmen",
        ///"eastup" : "/d/menpai/shaolin/shanlu_xiaojing",
    "south"  : __DIR__"tulu2",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

