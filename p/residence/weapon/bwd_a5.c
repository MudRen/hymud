#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[37m����֮����[2;37;0m", ({ "hongyu hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[37m����֮����[2;37;0m����һ���ɼ����Ӳ��[1;33m����[2;37;0m����[32m���˿[2;37;0m�Ƴɣ�������������Ǯ��[37m����֮����[2;37;0m��
�ۺ�����[37m������˫[2;37;0m �����������̣�����[36m��С[2;37;0m�ķ�������
������˼����ŷ��ţ�
[1;31mħ[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;32mħ��[2;37;0m [33m��[2;37;0m:[31m����[2;37;0m [1;35m��[2;37;0m:[1;32mħ��[2;37;0m 

���滹����һЩ���֣�
��Ӳ:[1;31m��Ԫ[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[34mϸ��[2;37;0m ����:[36m����[2;37;0m 
����:[33m�ܸ�[2;37;0m ����:[35m��׼[2;37;0m ����:[34mϸ��[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m�ν�[2;37;0m ������һЩ�� [1;32m����[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bwd");
		set("ownername", "�ν�");
		set("value", 16000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",0);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 22);
    set("armor_prop/attack", 16);


    set("armor_prop/armor", 84);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 45);
    set("armor_prop/qi", 55);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 606);

    set("wtypeA",0);
    set("wtypeB",9);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",6);
    set("wtypeF",9);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "hammer",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 320,              
                ]) );		


		set("material", "default");
    set("sharpness", 13);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";