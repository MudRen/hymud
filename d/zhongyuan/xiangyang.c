inherit ROOM;
void create()
{
  set("short","��������");
  set("long",@LONG
��������Ⱥɽ�����ٺ����������Ǵ�Ƭ������ũ��˿ڳ��ܡ������С��
����Ұ�䴩�������뺺�������Ǿ��ڽ�����������ԣ�������һ��С·��ͨ��
ˮ���Σ��ؽ����£���ɵ��ｭ�꣬���������ݣ����ݡ�
LONG);
  set("exits",([
    "north"   : __DIR__"fancheng",
    "west"  : __DIR__"xiaolu2",
   "southeast"  : "/d/xiangyang/westgate2",
     ]));
   set("outdoors","zhongyuan");
  setup();
}

