inherit ROOM;


void create()
{
   set("short","���̹�");
   set("long",@LONG
���̹��������������ϣ����������Ҫ�ؿ�֮һ��
    ���Ե���������ѣ����������족�������ɽ����խ��᫣�����һ�أ��岽
һ�գ���һ�����񣬾ͻ�ʧ�����ɽ����ˤ�÷�����ǡ�
LONG);
   set("exits",([
      "northeast"   : __DIR__"yangping_guan",
      "south"  : __DIR__"jianmen_guan",
   ]));
   setup();
        set("outdoors","xinan");
}
