 // Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
inherit ROOM;
void create()
{
  set("short","��ϼ��");
  set("long",@LONG
��ϼԪ����̩ɽŮ�񣬴�Ϊ�������֮��Ů�����ڲ������ܣ��ṹ
�Ͻ������羫�ɣ���̻Իͣ����й���һŮ�ӣ���ü��Ŀ������������
�����黨���ں�΢Ц����ǰ��𲻾�������ÿ������٣�����ӿ��
�ƺ����������ɽ��ڽԻ�Ϊ�Ǿ����칬��
LONG
  );
  set("exits",([
        "west" : __DIR__"nantian",
        "northup" : __DIR__"tianzhu",
        "northeast" : __DIR__"daguan",
        "east" : __DIR__"zhanlu",       
               ]));
        set("coor/x",330);
        set("coor/y",2390);
        set("coor/z",120);
        set("objects", ([
               __DIR__"npc/shengcunxiao" : 1,
                        ]) );
        
        setup();
        replace_program(ROOM);
} 
