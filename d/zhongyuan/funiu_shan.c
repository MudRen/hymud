inherit ROOM;
void create()
{
  set("short","��ţɽ");
  set("long",@LONG
���ƽ��ߣ����ܶ���ï�ܵ����֣�һ��С·�ϱ����졣�����ٸ������ɻ���
��˰���أ�һЩƶ��ũ��׷����Ϊ�ܡ�����ɽ�ϳ���ǿ����û����в������
�̡�һ�����ϣ����˶����Ҵ�ɽ�Ͼ��������ǰ�����ɽ������Ҳ���㷲����ģ�
����ǿ���������١�
LONG);
  set("exits",([
    "northeast"   : __DIR__"tulu4",
    "southeast"  : "/d/nanyang/beimen",
  ]));
  set("outdoors","zhongyuan");
  setup();
}

