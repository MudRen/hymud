inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
���ǳ�͢Ϊ�����ģ������ӣ���ʹ��ʮ�����޳ɵĴ����������һ��ƽ��
��·�ϲ�ʱ�����Źٷ����˲���ɱ����������˼��ˣ���ԶԶ�ܹ�һ�ߡ�
LONG);
  set("exits",([
    "west"   : __DIR__"guandao4",
    "east"   : __DIR__"guandao6",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

