inherit ROOM;
void create()
{
  set("short","�ٵ�");
  set("long",@LONG
���ǳ�͢Ϊ�����ģ������ӣ���ʹ��ʮ�����޳ɵĴ����·�ϲ�
ʱ�����Źٷ����˲���ɱ����������˼��ˣ���ԶԶ�ܹ�һ�ߡ�·����
һ��С·ֱͨ��ɽ��������������ˡ�
LONG);
  set("exits",([
    "west"   : __DIR__"guandao5",
    "east"   : __DIR__"tongguan",
//  "south": __DIR__"xiaolu1", 
  ]));
   set("outdoors","zhongyuan");
  setup();
}

