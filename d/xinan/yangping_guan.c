inherit ROOM;


void create()
{
  set("short","��ƽ��");
  set("long",@LONG
��ƽ�����м���ɽ���������꽭��������Ҫ���Թ�Ϊ��������Ľ�ͨ�ʺ�
    ���Ե���������ѣ����������족�������ɽ����խ��᫣�����һ�أ��岽
һ�գ���һ�����񣬾ͻ�ʧ�����ɽ����ˤ�÷�����ǡ�
LONG);
  set("exits",([
    "northdown"   : __DIR__"shanlu3",
    "southwest"  : __DIR__"qipan_guan",
  ]));
  setup();
        set("outdoors","xinan");
}
