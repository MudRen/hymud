 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "�ҽ���");
        set("long", @LONG 
·�����ˣ��ɸ��ӵ��±̺���ɳ��Ҳ��Զ�����ϰ��ƹ³ǣ������ƶ���ƺ�����
��ߣ���ν�ð��Ƶ����֮ݼ�����ڣ�Ҷ�³������ڴˣ�������־�� 
                           ��
                           ��
                           ��
                           �� 
LONG 
           ); 
        set("exits",  
           ([  
       "northdown" : __DIR__"jianlin",
       "southwest" : __DIR__"hillroad",
            ])); 
        set("objects",  
           ([  
       __DIR__"npc/guard2" : 1,
       __DIR__"npc/guard3" : 1,
            ])); 
        set("outdoors", "baiyun"); 
        set("coor/x",15); 
        set("coor/y",-1730); 
        set("coor/z",15); 
        setup(); 
        replace_program(ROOM); 
}  
