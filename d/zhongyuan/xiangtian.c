inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
�����ǳ����Ƕ��������ܶ����������¤�����ɢ�ż�Ͱ���é�ݡ�Զ����
һ��С��ׯ�����ƴ��̻�����Ʈɢ�ڿ��С�
LONG);
  set("exits",([
    "northwest"   : __DIR__"beijiao",
    "southwest"   : __DIR__"zhongnan_shan",
  ]));
   set("outdoors","zhongyuan");
setup();
}

