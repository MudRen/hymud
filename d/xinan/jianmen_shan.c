inherit ROOM;


void create()
{
   set("short","����ɽ");
   set("long",@LONG
����ɽ����һ������н�����ʮ���壬�ͱ��жϣ�������Ƕ�����ƽ��ţ�
�ʵô���������ʱ������󽫽�ά���ڴ����ӻ���š�����ȥ���������Ľ����
����
LONG);
   set("exits",([
     "north"   : __DIR__"jianmen_guan",
      "southwest"  : __DIR__"gudao1",
   ]));
   setup();
        set("outdoors","xinan");
}
