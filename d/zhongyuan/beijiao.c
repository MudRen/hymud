inherit ROOM;
void create()
{
  set("short","��������");
  set("long",@LONG
���������Ͼ��ǹŶ������ı����ˡ�ǰ�����Գ���Ϊ���������ƣ���������
���������ϰ����˾�ס������ʱ����Ǩ����ĩ�ķ׷�ս��ʹ��������֮��һ
��֮�仯Ϊ���棬�ʹ�˥����ȥ����Щ�����ǻԻ�һʱ�ľ޴��ΰ�Ĺ���ĵط���
����ȴ���ѱ����ũ�
LONG);
  set("exits",([
    "northeast"   : __DIR__"guandao3",
    "northwest"   : __DIR__"erfang",
  "southeast" : __DIR__"xiangtian",
  "south" : "/d/city4/road6",
  ]));
  setup();
   set("outdoors","zhongyuan");
}

