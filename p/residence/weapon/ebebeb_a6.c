#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[1;37m�ǹ⻤��[2;37;0m", ({ "good wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
��Ҷ֮����[2;37;0m����һ˫�ɷǳ���Ӳ��[1;37m����[2;37;0m����[1;33mľ�޻�[2;37;0m�Ƴɣ������������Ǯ��[1;37m��Ҷ֮����[2;37;0m��
�ۺ�����[1;34m��������[2;37;0m �������ǳ���̣�����[36mһ��[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;33m��[2;37;0m:[1;33m��ʥ[2;37;0m [31m��[2;37;0m:[32m�ֲ�[2;37;0m [33m��[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;36m����[2;37;0m 
[1;37m��[2;37;0m:[31m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;32mħ��[2;37;0m ����:[36m����[2;37;0m ����:[33mһ��[2;37;0m ����:[34mϸ��[2;37;0m 
��ʯ:[34mϸ��[2;37;0m ����:[34mϸ��[2;37;0m 
����:[36m����[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32mĽ����[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "ebebeb");
		set("ownername", "Ľ����");
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",12);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",10);
    set("armor_prop/dodge", 28);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 29);


    set("armor_prop/armor", 66);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 11);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 40);

    set("wtypeA",10);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",3);
    set("wtypeE",9);
    set("wtypeF",7);
    set("wtypeG",6);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    
    
                set("skill", ([
                        "name": "sword",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 9);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";