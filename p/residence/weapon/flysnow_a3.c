#include <ansi.h> 
#include <armor.h>

inherit SHIELD;

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
	      set_name("[1;37m����֮��[2;37;0m", ({ "general shield", "shield" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
ħ��֮��[2;37;0m����һ����ʮ�ּ�Ӳ��[1;32m��ʯ[2;37;0m����[1;33m����[2;37;0m�Ƴɣ������������Ǯ��[1;37mħ��֮��[2;37;0m��
�ۺ�����[31m��������[2;37;0m ������ʮ�ּ�̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[33m�ܸ�[2;37;0m [1;31mħ[2;37;0m:[33m�ܸ�[2;37;0m [1;33m��[2;37;0m:[31m����[2;37;0m [36mľ[2;37;0m:[33m�ܸ�[2;37;0m [1;34m��[2;37;0m:[1;34m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[33m�ܸ�[2;37;0m ����:[33mһ��[2;37;0m 
����:[33mһ��[2;37;0m 

�Լ�һ�Ź�׭�֡� [1;32m��ѩ[2;37;0m ������һЩ�� [1;32mָ��[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "flysnow");
		set("ownername", "��ѩ");
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 6);


    set("armor_prop/armor", 134);
    set("armor_prop/defense", 16);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",6);
    set("wtypeB",4);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",8);
    set("wtypeI",4);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",4);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 120,              
                ]) );		


		set("material", "default");
    set("sharpness", 4);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";