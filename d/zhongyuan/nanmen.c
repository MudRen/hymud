inherit ROOM;
void create()
{
        set("short","��������");
  set("long",@LONG
�����ǵ��񾩶��������쳣����δ��ǣ��Ѽ����ӻ��ģ��������ģ�ˣ��Ϸ
�ģ�����ʽ�ģ��ڳ�����һƬߺ��������������֡���¥��վ�ż����ٱ����̲�
�������͡�
LONG);
  set("exits",([
    "east"   : __DIR__"guandao7",
    "west"   : __DIR__"jianshui",
    "south"  : __DIR__"longmen",
    "northeast"  : "/d/luoyang/southgate",
  ]));
    set("outdoors","zhongyuan");
  set("valid_startroom","1");
  setup();
}

