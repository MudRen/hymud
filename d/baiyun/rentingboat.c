 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������ר��Ϊ��λ������ʿ�ṩ���ּ۸��������һ���ĺ�������ҵ�񣬾���
ϸ�����λ�ο��۸��ơ��ڴ��еĴ����м���м۸��ƣ�����һ�顣
LONG
           );
        set("exits", 
           ([
             "west" : __DIR__"southsearoad1",
            ]) );
        set("item_desc", 
           ([
             "sign": @TEXT
���ֺ��ṩ���⴬�����У� 
ľ�� (raft)��������㣬�������ˣ��ع���Ȼ�����ӷ��飬ֻ��50 ��������
С�� (boat)��һҶ���ۣ��沨���������˺ϳˣ��������飬ֻ��5000 ��������
���� (ship)������֮�ã�����ն�ˣ�����ƽ������͢���飬ֻ��50000 ��������;
TEXT
            ]) );
        set("objects", 
           ([
             __DIR__"npc/boatowner" : 1,
            ]) );
        set("coor/x",20);
        set("coor/y",-660);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
/*
//�����ṩ���⴬�����У�
//
//ľ�� (raft)             10 ��������
//С�� (boat)            100 ��������
//���� (ship)           1000 ��������
//
//��ӭ�ٴι��ٱ��ꡣ*/       
