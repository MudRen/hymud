#include <ansi.h> 
#include <armor.h>

inherit BOOTS;

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
	      set_name("[1;32m¬÷ªÿ∑®÷€«·[2;37;0m", ({ "good boots", "boots" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "À´");
		set("long", @LONG
¿À‘∆÷Æ—•[2;37;0m’‚ «“ªÀ´”…Œﬁ±»º·”≤µƒ[31m¡˜ª® Ø[2;37;0mº”…œ[1;37m≤œÀø[2;37;0m÷∆≥…£¨÷ÿ“ªΩÔ¡˘¡Ω∞À«Æµƒ[1;32m¿À‘∆÷Æ—•[2;37;0m°£
◊€∫œ∆¿º€[1;34mæŸ ¿∫±º˚[2;37;0m ø¥∆¿¥Œﬁ±»º·πÃ£¨æﬂ”–[36m“ª∞„[2;37;0mµƒ∑¿ª§¡¶£°
…œ√ÊøÃ¡Àº∏∏ˆπ≈∑˚∫≈£∫
[1;34mµÁ[2;37;0m:[1;33mÃÏ •[2;37;0m 
…œ√ÊªπøÃ¡À“ª–©∑˚◊÷£∫
º·”≤:[1;32mƒßÕı[2;37;0m ÃÏ”Ó:[36m≤ª¥Ì[2;37;0m «…÷∆:[36m≤ª¥Ì[2;37;0m 

“‘º∞“ª≈≈π≈◊≠◊÷°æ [1;32m∆∆¿√’æ[2;37;0m °ø°£∫Õ“ª–©°æ [1;32mµ∂∑®[2;37;0m °øµƒºº«…°£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "lyaxu");
		set("ownername", "∆∆¿√’æ");
		set("value", 9000);
		set("armor_prop/intelligence",16);
		set("armor_prop/strength",17);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 0);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 54);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",0);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",10);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    
    
                set("skill", ([
                        "name": "blade",
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