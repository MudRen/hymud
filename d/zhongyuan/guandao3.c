inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
���ǳ�͢Ϊ�����ģ������ӣ���ʹ��ʮ�����޳ɵĴ�������ܽ���һ��ƽ
����ֻ��������һ����ɽ���Ǿ��ǡ����������Ϸ������ɽ��ɽ������һƬ
��¥���棬��˵���ǵ����������ԡ�Ļ��幬��
LONG);
  set("exits",([
    "southwest"   : __DIR__"beijiao",
    "east"   : __DIR__"guandao4",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

