inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
���ǳ�͢Ϊ�����ģ������ӣ���ʹ��ʮ�����޳ɵĴ����������һ��ƽ��
��·�ϲ�ʱ�����Źٷ����˲���ɱ����������˼��ˣ���ԶԶ�ܹ�һ�ߡ��ϱ���
һ��ɽ·���������۵�ͨ�����롣
LONG);
  set("exits",([
    "west"   : __DIR__"guandao1",
       "east" : __DIR__"erfang",
      "southwest" : "/d/xinan/shanlu1",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

