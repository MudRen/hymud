inherit ROOM;


void create()
{
   set("short","����ƽԭ");
   set("long",@LONG
�Ĵ����������ůʪ�����ط������ɽ��ˮ�㣬����ḻ��һ���С���
��֮���������ơ��������칫�����������˳����Ȼ�ٸ������տ�����˰������
Ҳ���ܹ���ȥ��
LONG);
   set("exits",([
      "northwest" : __DIR__"dujiang_yan",
//    "east"   : __DIR__"chengdu",
      "southwest"  : __DIR__"pingyuan8",
      "north"    : __DIR__"pingyuan6",
  ]));
  setup();
        set("outdoors","xinan");
}
