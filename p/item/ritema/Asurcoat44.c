#include <ansi.h> 
#include <armor.h>

inherit SURCOAT;

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
	      set_name("[34mÈÍÖ®¶Ç´ø[2;37;0m", ({ "bad surcoat", "surcoat" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "Ìõ");
		set("long", @LONG
ÈÍÖ®¶Ç´ø[2;37;0mÕâÊÇÒ»ÌõÓÉÊ®·Ö¼áÓ²µÄ¾«¸Ö¼ÓÉÏ[1;37mÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÁã½ï°ËÁ½ÆßÇ®µÄ[34mÈÍÖ®¶Ç´ø[2;37;0m¡£
×ÛºÏÆÀ¼Û[32m¾«ÖÂÏ¸ÃÀ[2;37;0m ¿´ÆğÀ´Ê®·Ö¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[35m±ê×¼[2;37;0m [1;34mµç[2;37;0m:[31m¾«ÖÂ[2;37;0m [1;31mÄ§[2;37;0m:[34mÏ¸Ëé[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[36m²»´í[2;37;0m ÌìÓî:[32m¼«²î[2;37;0m ÌìĞş:[32m¼«²î[2;37;0m ÇÉÖÆ:[32m¼«²î[2;37;0m 
×ÏÊ¯:[33mÒ»°ã[2;37;0m ÍşÁ¦:[32m¼«²î[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 2000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",3);
		set("armor_prop/karey",0);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",3);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 7);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 14);
    set("armor_prop/defense", 0);
    
    set("armor_prop/neili", 0);
    set("armor_prop/qi", 0);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 0);
    set("armor_prop/damage", 1);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",2);
    
    
                set("skill", ([
                        "name": "leg",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 50,              
                ]) );		


		set("material", "default");
    set("sharpness", 1);
        }
        setup();
}



#include "/obj/ritem/armorzy.h";