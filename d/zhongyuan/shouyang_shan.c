inherit ROOM;
void create()
{
  set("short","����ɽ");
  set("long",@LONG
��˵�����������̺󣬹�������Ķ��Ӳ��ģ���������򲻿ϳ��ܳ�����ʳ
���Ͷ������ɽ�ϣ�������������ɽ�ϻ���һ��ʯ������¼�ŵ�������˵���
����
LONG);
  set("exits",([
    "eastdown"   : __DIR__"zhongnan_shan",
 "westup"   : "/d/quanzhen/shanjiao",
 ]));
   set("outdoors","zhongyuan");

  setup();
}

