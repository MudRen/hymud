inherit ROOM;


void create()
{
   set("short","����ƽԭ");
   set("long",@LONG
�Ĵ����������ůʪ�����ط������ɽ��ˮ�㣬����ḻ��һ���С���
��֮���������ơ��������칫�����������˳����Ȼ�ٸ������տ�����˰������
Ҳ���ܹ���ȥ��
    ������һƬ���ʵ�Ⱥɽ����������һƬ��ƽԭ��
LONG);
   set("exits",([
      "northup"   : __DIR__"gudao3",
      "south"  : __DIR__"pingyuan2",
      "west" : __DIR__"pingyuan9",
   ]));
   setup();
        set("outdoors","xinan");
}
