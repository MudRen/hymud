inherit ROOM;


void create()
{
   set("short","��ɽ");
   set("long",@LONG
��ɽ�ش�ẽ����ɺӽ���֮������ɽ��������ˮ���ƣ�ˮ��һɫ֮�и���
��������ɽ���ʯ�񣬡�����ɽ��ɽ���Ƿ𡱣����������Ŀ�ĺ�ȥ������ȥ
���Ƕ���ɽ�ˡ�������ɽ�Ϸ����ս����࣬���ʢ�������н�������ݷ���
���Ǵ�ɺӡ�
LONG);
   set("exits",([
      "north"   : __DIR__"pingyuan8",
      "northwest"    : "/d/emei/caopeng",
      "southwest"  : __DIR__"dadu_hebian",
   ]));
   set("outdoors","xinan");
   
   setup();
}
