inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
�������������ϣ�Խ���׺ӣ�����һƬ���ֵ�ũ�������Ϲ��˺�����������
���ˣ��׺��Գ��»��������Ϸ���ż��������ں����������㣬������ͩ��ɽ��
��ɽ��ȥ���ٹ��˴�ʤ�ؾͿɵִｭ��������
LONG);
  set("exits",([
    "north"   : __DIR__"nanyang_jie",
    "southwest"  : __DIR__"baihe_an",
  ]));
   set("outdoors","zhongyuan");
  setup();
   replace_program(ROOM);
}

