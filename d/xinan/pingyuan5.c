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
      "northeast"   : __DIR__"pingyuan4",
      "southwest"  : __DIR__"pingyuan6",
  ]));
  setup();
        set("outdoors","xinan");
}
