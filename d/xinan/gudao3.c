inherit ROOM;


void create()
{
   set("short","����ŵ�");
   set("long",@LONG
����ʱ�ڣ��������佣ɽ����ջ����ʮ�����������գ��ɸ�ͨ�ڡ�.
ջ����Ƕ�����°�;��������ߣ�һֱ������Ҫ�ء������Ǳ��ڵĽ�ˮ������
֮���쳹ɽ�ȡ���������ɽ��һƬ������ƽԭ��
LONG);
   set("exits",([
      "northeast"   : __DIR__"gudao2",
     "southdown"  : __DIR__"pingyuan1",
   ]));
   setup();
        set("outdoors","xinan");
}
