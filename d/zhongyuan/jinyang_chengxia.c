// jinyang_chengxia.c
inherit ROOM;

void create()
{   
    set("short","��������");
    set("long",@LONG
���߼��ǽ����ǡ�������֮�Ǽ�ع㣬�ԡ����ҷֽ����Ǿ���Ϊ������ʷ��
��˵�����ƶ����Է����ڴˡ�̫�ڻʵ�ˮ�ͽ����ǣ��𱱺��ڴˣ��򹥳����ã�
Ǩŭ֮�£�����ٳǳأ������³ǣ����ڵ��˳Ǳ�ϵ��ɽ��ɽ�����ǣ�������
����ֻ�޶���·���Զ��������������ڵĽ����Ǳ�ԭ����С���ˡ�
LONG );
    set("exits",([
        "southwest" : __DIR__"jinci",
        "north" : __DIR__"yidao1",
        "east"  : __DIR__"yidao9"     ]) );
    set("outdoors","zhongyuan");
    setup();
}
