// zhongtiao_shan3.c
inherit ROOM;

void create()
{   
    set("short","����ɽ");
    set("long",@LONG
����ɽ����һ�������ب�ڻƺӱ����������ǰ���֮һ�Ź�����������֮
��������ë¿���Ź��ϵ�����һֱ�ڱ����Ĵ�ͷ��Ұ�������š���˵�Ƴ�ʱ��
��������죬������¡������گ������������ÿ�������ڴ��͹�ǰ���ض�������
ʬ�����������������ɹ��󲻾ã������˼�������ɽ�����Σ����ɵ�����������
���
LONG );
    set("exits",([
        "southwest" : __DIR__"zhongtiao_shan2",
        "northeast" : __DIR__"xiaxian"  ]) );
    set("outdoors","zhongyuan");
    setup();
}
