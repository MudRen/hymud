#include <ansi.h> 
#include <armor.h>

inherit NECK;

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
	      set_name("[34m»Ã·çÖ®ÏîÁ´[2;37;0m", ({ "good neck", "neck" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "´®");
		set("long", @LONG
»Ã·çÖ®ÏîÁ´[2;37;0mÕâÊÇÒ»´®ÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0m¼ÓÉÏ[1;33mÄ¾ÃŞ»¨[2;37;0mÖÆ³É£¬ÖØÈı½ïÈıÁ½ÎåÇ®µÄ[34m»Ã·çÖ®ÏîÁ´[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;34m¾ÙÊÀº±¼û[2;37;0m ¿´ÆğÀ´ÎŞ±È¼á¹Ì£¬¾ßÓĞ[36mÒ»°ã[2;37;0mµÄ·À»¤Á¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[1;33m½ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m [36mÄ¾[2;37;0m:[35m±ê×¼[2;37;0m [32mË®[2;37;0m:[1;33mÌìÊ¥[2;37;0m [31m»ğ[2;37;0m:[1;32mÄ§Íõ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
¼áÓ²:[1;33mÌìÊ¥[2;37;0m ¸£Ô´:[36m²»´í[2;37;0m 
ÇÉÖÆ:[32m´Ö²Ú[2;37;0m 
ÖÜÌì:[32m´Ö²Ú[2;37;0m ³¤Éú:[36m²»´í[2;37;0m ²»ÀÏ:[36m²»´í[2;37;0m 
ÒÔ¼°Ò»ÅÅ¹Å×­×Ö¡¾ [1;32mĞÇÒş[2;37;0m ¡¿¡£ºÍÒ»Ğ©¡¾ [1;32mµ¶·¨[2;37;0m ¡¿µÄ¼¼ÇÉ¡£

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "bbm");
		set("ownername", "ĞÇÒş");
		set("value", 9000);
		set("armor_prop/intelligence",0);
		set("armor_prop/strength",24);
		set("armor_prop/karey",12);
		set("armor_prop/percao",0);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",32);
    set("armor_prop/dodge", 24);
    set("armor_prop/parry", 40);
    set("armor_prop/attack", 0);


    set("armor_prop/armor", 96);
    set("armor_prop/defense", 24);
    
    set("armor_prop/neili", 37);
    set("armor_prop/qi", 12);
    set("armor_prop/jing", 16);
    set("armor_prop/jingli", 16);
    set("armor_prop/damage", 79);

    set("wtypeA",9);
    set("wtypeB",5);
    set("wtypeC",10);
    set("wtypeD",9);
    set("wtypeE",3);
    set("wtypeF",0);
    set("wtypeG",4);
    set("wtypeH",0);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",1);
    
    
                set("skill", ([
                        "name": "blade",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 240,              
                ]) );		


		set("material", "default");
    set("sharpness", 10);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";