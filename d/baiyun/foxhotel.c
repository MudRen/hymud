 //Created by justdoit at May 2001
//All Rights Reserved ^_^ 
 
inherit ROOM; 
void create() 
{ 
        set("short", "������"); 
        set("long", @LONG 
����Ʈ���ں��ϵ����ǣ����𡰺����ѡ��������֣��ͻ�¶�����ض�����΢Ц��
����Ҳ����û������ģ��ͺ���պ��˱��Ҿơ�ֻҪ����������õ����£��ں�����
�ﶼ�����ҵõ�����ľ���ɵ������Ѻ��ƾɣ�����û���ں�����ů��ʪ�ĺ���Ӵ�
��ĺ��ϴ�����������������������ζ���������������ڣ�Ů��ͷ�ϵ��ٻ�����ζ
�������ζ������ڡ������Լ��������ǵĸ���������
LONG 
           ); 
        set("exits",  
           ([  
//           "north" : __DIR__"southsearoad", 
//           "south" : __DIR__"southsearoad2", 
//           "west"  : __DIR__"teashop" 
             "east"  : __DIR__"southsearoad" 
            ])); 
       set("objects", 
          ([ 
        __DIR__"npc/niuroutang" : 1,
            ]));
    set("indoors", "baiyun");
        set("coor/x",0); 
        set("coor/y",-650); 
        set("coor/z",0); 
        setup(); 
        replace_program(ROOM); 
}      
