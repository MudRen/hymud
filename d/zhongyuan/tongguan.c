inherit ROOM;
void create()
{
  set("short","����");
  set("long",@LONG
�����ǰ˰�����е�������ϡ������ϱ����Ǹ�ɽ���룬�ƺӼйض�������
һ�򵱹أ����Ī�������ƻƳ�����ʱ����ʮ�������֮���ˣ����������ҵ�һ
��С·�ƹ��ؿڲŵ���ͨ������ӿ�Ļƺ��ڴ��ɴӹ������¸�����ȥ���Ӷ԰�
�Ƿ���ɶɿڣ�һ�����ź�ܺ��ϣ������ϸ��������ɸߵ�ͭţ˩ס������
LONG);
  set("exits",([
    "west"   : __DIR__"guandao6",
//    "northeast" : __DIR__"fengling_du",
    "southeast"   : __DIR__"hangu_guan",
  ]));
   set("outdoors","zhongyuan");
  setup();
}

