inherit ROOM;
void create()
{
    set("short","ɽ·");
    set("long",@LONG
�����ѵ��أ�μ���ݽ���֮�������ƽ��ߣ�����������ɽ������������
������ɽ��һֱ�ߣ�������Ƭ�߾�����������ľ����ˡ�����ɽ�ϲ�ʱ�ɼ���
�﷿�ᡣ
LONG);
    set("exits",([
        "north"   : __DIR__"kongdong_shan",
        "southwest"  : __DIR__"qinzhou_fu",
  ]));
set("outdoors","xibei");
  setup();
}

