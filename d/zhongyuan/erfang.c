inherit ROOM;
void create()
{
  set("short","������ַ");
  set("long",@LONG
��ʼ������������Ϊ��������ԭ������Ĺ�ģ�����ڴ˵ؽ����ˡ��Ͽ���
���ˣ��¿ɽ������족�İ�������˭�Ͻ�������󣬱�����������һ�������
�����������񹬵����ѵ�Ȼ�޴棬ֻʣ·��ɽ����һ��ƽ̹�ĵػ����������
�������˽����Ź��ϵĹ��¡�
LONG);
  set("exits",([
    "southeast"   : __DIR__"beijiao",
    "west"   : __DIR__"guandao2",
  ]));
   set("outdoors","zhongyuan");
   setup();
}

