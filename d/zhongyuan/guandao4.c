inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
���ǳ�͢Ϊ�����ģ������ӣ���ʹ��ʮ�����޳ɵĴ�������ܽ���һ��ƽ
����������һ������Ĺ�Ĺ������ģģ�������С��޺�����֮Ĺ�������֡���·
�����˺ܶ࣬��ʱ��һ�Ӷ�����Ĺ��ͷɱ�������Ҳż���о�ʿ�����ң�����
�����ܵ���һ����һ�㡣
LONG);
  set("exits",([
    "west"   : __DIR__"guandao3",
    "east"   : __DIR__"guandao5",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

